#include "ns3/aodv-module.h"
using namespace ns3;

void setupRouting(InternetStackHelper &stack) {
    AodvHelper aodv;
    stack.SetRoutingHelper(aodv);
}
