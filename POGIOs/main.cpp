// to generate random graph and test the POGIOs.
#include "../graphgen/AdjLst/adjlst.hpp"
#include "../graphgen/AdjMatrix/adjmat.hpp"

#include "PreOrder/Online/PreOGIOnline.hpp"
//#include "PostOrder/Online/PostOGIOnline.hpp"
// #include "PreOrder/Offline/PreOGIOffline.hpp"
// #include "PostOrder/Offline/PostOGIOffline.hpp"

using namespace POGIO;
using namespace graphs;

int main () {

    AdjMatrix<int> g;
    g.Randomize(10);
    g.PrintAdjMatInfo();

    std::cout << std::endl;

    PreOGIOnline<int> pre_ogi_on(g, 0);
    while(!pre_ogi_on.isTerminated()) {
        std::cout << *pre_ogi_on << " ";
        ++pre_ogi_on;
    } 

    std::cout << std::endl;



    return 0;
}