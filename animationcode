#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/internet-module.h"
#include "ns3/wifi-module.h"
#include "ns3/aodv-module.h"
#include "ns3/applications-module.h"
#include "ns3/netanim-module.h"

#include <cstdlib>
#include <ctime>

using namespace ns3;

int main() {

    uint32_t nNodes = 100;
    uint32_t maliciousNode = 25;

    srand(time(0));

    NodeContainer nodes;
    nodes.Create(nNodes);

    // ---------------- TRUST ----------------
    std::vector<double> trust(nNodes, 1.0);
    trust[maliciousNode] = 0.0;

    // ---------------- WIFI ----------------
    WifiHelper wifi;
    wifi.SetStandard(WIFI_STANDARD_80211b);

    YansWifiChannelHelper channel = YansWifiChannelHelper::Default();
    channel.AddPropagationLoss("ns3::RangePropagationLossModel",
                               "MaxRange", DoubleValue(150.0));

    YansWifiPhyHelper phy;
    phy.SetChannel(channel.Create());

    // Slightly reduced power to avoid hub dominance
    phy.Set("TxPowerStart", DoubleValue(16.0));
    phy.Set("TxPowerEnd", DoubleValue(16.0));

    WifiMacHelper mac;
    mac.SetType("ns3::AdhocWifiMac");

    NetDeviceContainer devices = wifi.Install(phy, mac, nodes);

    // ---------------- MOBILITY ----------------
    MobilityHelper mobility;

    mobility.SetPositionAllocator("ns3::GridPositionAllocator",
        "MinX", DoubleValue(0.0),
        "MinY", DoubleValue(0.0),
        "DeltaX", DoubleValue(20.0),
        "DeltaY", DoubleValue(20.0),
        "GridWidth", UintegerValue(10),
        "LayoutType", StringValue("RowFirst"));

    mobility.SetMobilityModel("ns3::RandomWalk2dMobilityModel",
        "Bounds", RectangleValue(Rectangle(0, 400, 0, 400)));

    mobility.Install(nodes);

    // ---------------- INTERNET ----------------
    AodvHelper aodv;
    InternetStackHelper stack;
    stack.SetRoutingHelper(aodv);
    stack.Install(nodes);

    Ipv4AddressHelper address;
    address.SetBase("10.1.1.0", "255.255.255.0");
    Ipv4InterfaceContainer interfaces = address.Assign(devices);

    uint16_t port = 9;

    // ---------------- SERVERS ----------------
    for (uint32_t i = 0; i < nNodes; i++) {
        UdpEchoServerHelper server(port);
        ApplicationContainer sApp = server.Install(nodes.Get(i));
        sApp.Start(Seconds(1.0));
        sApp.Stop(Seconds(30.0));
    }

    // Random start time generator
    Ptr<UniformRandomVariable> uv = CreateObject<UniformRandomVariable>();
    uv->SetAttribute("Min", DoubleValue(2.0));
    uv->SetAttribute("Max", DoubleValue(25.0));

    // ---------------- TRUST-CENTRIC TRAFFIC ----------------
    for (uint32_t i = 0; i < nNodes; i++) {

        uint32_t src = i;
        uint32_t dst = rand() % nNodes;

        // avoid self, malicious, and nearby nodes (reduces clustering)
        while (dst == src || dst == maliciousNode || std::abs((int)dst - (int)src) < 10)
            dst = rand() % nNodes;

        // skip malicious node
        if (src == maliciousNode)
            continue;

        // trust filter
        if (trust[src] < 0.5 || trust[dst] < 0.5)
            continue;

        // balanced packet drop (10%)
        if (rand() % 10 < 1) {
            if (rand() % 20 == 0)
                std::cout << "Packet dropped (trust)\n";
            continue;
        }

        UdpEchoClientHelper client(interfaces.GetAddress(dst), port);
        client.SetAttribute("MaxPackets", UintegerValue(25));
        client.SetAttribute("Interval", TimeValue(Seconds(0.7)));
        client.SetAttribute("PacketSize", UintegerValue(512));

        ApplicationContainer app = client.Install(nodes.Get(src));
        app.Start(Seconds(uv->GetValue()));
        app.Stop(Seconds(30.0));
    }

    // ---------------- ANIMATION ----------------
    AnimationInterface anim("anim.xml");

    anim.SetMaxPktsPerTraceFile(300000);
    anim.EnablePacketMetadata(false);

    for (uint32_t i = 0; i < nNodes; i++) {
        if (i == maliciousNode)
            anim.UpdateNodeColor(i, 255, 0, 0);
        else
            anim.UpdateNodeColor(i, 0, 200, 0);
    }

    std::cout << "\nMalicious Node: " << maliciousNode << std::endl;

    Simulator::Stop(Seconds(30.0));
    Simulator::Run();
    Simulator::Destroy();

    return 0;
}
