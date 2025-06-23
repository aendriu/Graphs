#ifndef AJDLIST
#define AJDLIST

#include "../graph/graph.hpp"

namespace graphs {
template<typename Data>
class AdjList : public Graph<Data> {
    private:
        // Private members can be added here if needed

    protected:
        // Protected members can be added here if needed

    public:
        // Constructor
        AdjList() = default;

        // Destructor
        virtual ~AdjList() = default;

        // Copy Assignment
        AdjList &operator=(const AdjList&) = delete;

        // Move Assignment
        AdjList &operator=(AdjList&&) noexcept = delete;

        // Other member functions can be declared here


};


}



#endif