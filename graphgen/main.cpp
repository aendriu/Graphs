#include "AdjLst/adjlst.hpp"
#include "AdjMatrix/adjmat.hpp"

using namespace graphs;
int main(int argc, char* argv[]) {
    
    AdjMatrix<int> g(5);
    vector<int> v = {1, 2, 3, 4, 5};

    g.setElements(v);
    g.PrintAdjMatInfo();
    
    std::cout  << std::endl;
    
    g.addLink(2, 3);
    g.PrintAdjMatInfo();

    std::cout << std::endl;
    
    g.removeLink(2,3);
    g.PrintAdjMatInfo();

    std::cout << std::endl;

    g.Randomize(10);
    g.PrintAdjMatInfo();
    
    std::cout << std::endl;
    
    std::cout << g[2];
    
    std::cout << std::endl;

    std::cout << g.Size();

    std::cout << std::endl;


    
    return 0;
}
