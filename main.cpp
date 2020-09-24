#include <iostream>
#include <fstream>      // std::filebuf

#include <IMC/Base/Packet.hpp>
#include <IMC/Spec/PlanSpecification.hpp>
#include <IMC/Spec/MsgList.hpp>
#include <IMC/Spec/Maneuver.hpp>
#include <IMC/Base/Packet.hpp>
#include <UDP/DatagramSocket.h>


int main(){
    std::cout << "Hello!";   


    //Create PlanSpecification object and add values
    IMC::PlanSpecification planSpec;
    planSpec.setTimeStamp(1.5628304294681385E9);
    planSpec.setSource(16652);
    planSpec.setSourceEntity(44);
    planSpec.setDestination(30);
    planSpec.setDestinationEntity(255);
    planSpec.description = "";
    planSpec.vnamespace = "";
    planSpec.start_man_id = "1";
    planSpec.plan_id = "cmd-lauv-xplore-1";

    IMC::PlanManeuver planManeuver;
    planManeuver.maneuver_id = "1";

    //How to add values to maneuvers, start_actions and end_actions??
    IMC::InlineMessage<IMC::Maneuver> data;

    planManeuver.toText(std::cout);
    planSpec.maneuvers.push_back(&planManeuver);

    //Write text to console
    planSpec.toText(std::cout);

    //Write to socket
    char localhost[] = "127.0.0.1"; 
    int port = 6002;
    int size = planSpec.getSerializationSize();
    char buffer[size];
    Packet::serialize(&planSpec, (uint8_t *) buffer, size);
    DatagramSocket socket(port, localhost, true, true); 
    socket.sendTo(buffer, size, localhost);

    std::cout << "Check JSON in json_out.txt\n\r";

    //Save JSON in txt-file
    std::filebuf fb;
    fb.open ("json_out.txt",std::ios::out);
    std::ostream os(&fb);
    planSpec.toJSON( os);
    fb.close();

    return 0;
}