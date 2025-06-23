#ifndef PREOGIONLINE
#define PREOGIONLINE

#include "../../giter.hpp"
#include <stack>

namespace POGIO {

template<typename Data>
class PreOGIOnline : virtual public Giter<Data> {
    protected:
        
        const graphs::Graph<Data>& G;
        std::stack<Data> toVisit;
        std::vector<char> Colors;
        long cur;
        
    public: 
        ~PreOGIOnline() override = default;
        PreOGIOnline(const graphs::Graph<Data>&, ulong);

        bool isTerminated() const noexcept override;
        const Data& operator*() const override;
        PreOGIOnline& operator++() override;    
        void Reset(ulong) override;

    protected:
        void Init() noexcept;


};

} 

#include "PreOGIOnline.cpp" 
#endif
