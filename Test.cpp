#include <iostream>
#include <stdexcept>

#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
using namespace std;


TEST_CASE("Init Game"){
    Board board ;
    CHECK (board.is_clean());
    CHECK_THROWS(board[City::Chicago] = -2);
    Player player (board, City::Chicago);
    player.take_card(City::Chicago);
    CHECK_THROWS(player.treat(City::Chicago)); // should throw because Chicago level is 0 
    board[City::Chicago] = 1;
    CHECK (!board.is_clean());
    player.treat(City::Chicago);
    CHECK (board[City::Chicago] == 0) ;
    CHECK (board.is_clean());

    // Check the connect between citys 
    Player a (board, City::Lagos);
    Player b (board, City::Mumbai);
    CHECK_THROWS (a.drive(City::Bogota)); // fly direct to unconnected city
    CHECK_THROWS (a.drive(City::Algiers)); // fly direct to unconnected city
    CHECK_THROWS (a.drive(City::Mumbai)); // fly direct to unconnected city
    a.take_card(City::Lagos);
    b.take_card(City::Mumbai);
    a.build();
    CHECK_THROWS(a.fly_shuttle(City::Mumbai)); // there is no research staion at Mumbai yet
    b.build();
    CHECK_NOTHROW(a.fly_shuttle(City::Mumbai)); // now there is one at Mumbai 

}

 TEST_CASE("Check spacial options to players"){
        Board jobs ;


        //OperationsExpert
        OperationsExpert operations_expert(jobs,City::Atlanta);
        CHECK_THROWS(operations_expert.treat(City::Atlanta)); // the level of disease is 0 
        CHECK_NOTHROW(operations_expert.build()); //should build even have no cards

        //Dispatcher
        Dispatcher dispatcher (jobs, City::Atlanta);
        CHECK_THROWS(dispatcher.treat(City::Atlanta)); // the level of disease is 0 
        CHECK_NOTHROW(dispatcher.fly_direct(City::Bangkok)); //should fly cuz there is research staion at Atlanta

        //Scientist
        Scientist scientist(jobs, City::Atlanta, 4);
        CHECK_THROWS(scientist.treat(City::Atlanta)); // the level of disease is 0 
        scientist.take_card(City::HongKong);
        scientist.take_card(City::Taipei);
        scientist.take_card(City::Beijing);
        scientist.take_card(City::Seoul);
        CHECK_NOTHROW(scientist.discover_cure(Color::Red));//should find cure with 4 cards

        Scientist scientist2(jobs, City::Atlanta);
        scientist.take_card(City::NewYork);
        scientist.take_card(City::London);
        scientist.take_card(City::Montreal);
        scientist.take_card(City::SanFrancisco);
        CHECK_NOTHROW(scientist.discover_cure(Color::Blue));//cant find cure with 4 cards cuz in the cunstrector we didnt give him n = 4  


        //Researcher
        Researcher researcher (jobs, City::Riyadh);
        CHECK_THROWS(researcher.treat(City::Riyadh)); // the level of disease is 0 
        researcher.take_card(City::Moscow);
        researcher.take_card(City::Kolkata);
        researcher.take_card(City::Cairo);
        researcher.take_card(City::Istanbul);
        researcher.take_card(City::Karachi);
        CHECK_NOTHROW(researcher.discover_cure(Color::Black));// even there is no research staion at Riyadh should discover

        //Medic
        Medic medic (jobs, City::Istanbul);
        CHECK_THROWS(medic.treat(City::Istanbul)); // the level of disease is 0 
        jobs[City::Milan] = 3 ;
        CHECK(!jobs.is_clean());
        CHECK_NOTHROW(medic.drive(City::Milan));
        CHECK(jobs.is_clean()); // there is cure for blue and if medic come to Milan should be cleaned
        medic.take_card(City::Shanghai);
        CHECK_NOTHROW(medic.fly_direct(City::Shanghai)); //city color red there is no cure yet
        jobs[City::Shanghai] = 3 ;
        CHECK(!jobs.is_clean());
        CHECK_NOTHROW(medic.treat(City::Shanghai)); //should clean all even there is no cure yet
        CHECK(jobs.is_clean());

        //Virologist
        Virologist virologist(jobs, City::Lima);
        CHECK_THROWS(virologist.treat(City::Lima)); // the level of disease is 0 
        virologist.take_card(City::Delhi);
        CHECK_THROWS(virologist.treat(City::Delhi)); // should throw cuz Delhi = 0
        jobs[City::Delhi] = 3 ;
        CHECK(!jobs.is_clean());
        CHECK_NOTHROW(virologist.treat(City::Delhi));
        CHECK(jobs.is_clean());

        //GeneSplicer
        GeneSplicer gene_splicer(jobs,City::SaoPaulo); //City with research staion
        CHECK_THROWS(gene_splicer.treat(City::SaoPaulo)); // the level of disease is 0 
        OperationsExpert operations_expert2(jobs,City::SaoPaulo);
        CHECK_NOTHROW(operations_expert2.build());
        CHECK(jobs.is_clean());
        jobs[City::SaoPaulo] = 3 ;
        CHECK(!jobs.is_clean());
        gene_splicer.take_card(City::Tokyo); //red
        gene_splicer.take_card(City::MexicoCity); //yellow
        gene_splicer.take_card(City::LosAngeles); //yellow
        gene_splicer.take_card(City::StPetersburg);//blue
        gene_splicer.take_card(City::Essen);//blue
        CHECK_NOTHROW(gene_splicer.discover_cure(Color::Yellow)); //should work even there is no five yellow cards
        gene_splicer.treat(City::SaoPaulo);
        CHECK(jobs.is_clean());

        //FieldDoctor
        FieldDoctor field_doctor(jobs, City::Khartoum);
        CHECK_THROWS(field_doctor.treat(City::Khartoum)); // the level of disease is 0 
        CHECK(jobs.is_clean());
        jobs[City::Cairo] = 3 ; // connected to Khartoum 
        CHECK(!jobs.is_clean());
        CHECK_NOTHROW(field_doctor.treat(City::Cairo));
        CHECK(jobs.is_clean());

        CHECK_EQ (operations_expert.role(),"OperationsExpert");
        CHECK_EQ (dispatcher.role(),"Dispatcher");
        CHECK_EQ (scientist.role(),"Scientist");
        CHECK_EQ (researcher.role(),"Researcher");
        CHECK_EQ (medic.role(),"Medic");
        CHECK_EQ (virologist.role(),"Virologist");
        CHECK_EQ (gene_splicer.role(),"GeneSplicer");
        CHECK_EQ (field_doctor.role(),"FieldDoctor");
 











    


        








    }