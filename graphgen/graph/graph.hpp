#ifndef GRAPH
#define GRAPH


namespace graphs {

using ulong = unsigned long;

template<typename Data>
class Graph {

    private:

    protected:

        ulong vcard;


    
    public:
        
        
        virtual ~Graph() = default;

        //Copy Assignment
        Graph &operator=(const Graph&) = delete;

        //Move Assignment
        Graph &operator=(Graph&&) noexcept = delete;

        //op[]
        virtual const Data& operator[](const ulong pos) const = 0;
        virtual Data& operator[](const ulong pos) = 0;

        //Spec member funct
        
        virtual bool hasLink(ulong, ulong) const = 0;
        virtual void addLink(ulong, ulong) = 0;
        virtual void removeLink(ulong, ulong) = 0;

        virtual ulong Size() const noexcept = 0;



};





}




#endif 