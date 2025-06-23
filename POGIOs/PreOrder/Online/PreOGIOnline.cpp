namespace POGIO {

/* ***** Constructor ***** */
template<typename Data>
PreOGIOnline<Data>::PreOGIOnline(const graphs::Graph<Data>& g, ulong start) : G(g) {
    if(start >= G.Size()) {
        throw(std::out_of_range("Start Element is out of bounds!!\n(while constructing)"));
    }
    Init();
    Colors[start] = 'b';
    toVisit.push(start);
    ++(*this);
}

/* ***** Specific Member Function ***** */
template<typename Data>
bool PreOGIOnline<Data>::isTerminated() const noexcept {
    return toVisit.empty();
}

/* ***** */

template<typename Data>
const Data& PreOGIOnline<Data>::operator*() const {
    return G[cur];
}

/* ***** */

template<typename Data>
PreOGIOnline<Data>& PreOGIOnline<Data>::operator++() {
    if(!toVisit.empty()) {
        ulong src = toVisit.top();
        toVisit.pop();
        cur = src;
         
        // aggiungo tutti gli adiacenti a toVisit
        for (ulong i = G.Size(); i-- > 0;) {
            if (G.hasLink(src, i) && Colors[i] == 'w') {
                Colors[i] = 'b';
                toVisit.push(i);
        }
    }

    }
    return *this;
}

/* ***** */

template<typename Data>
void PreOGIOnline<Data>::Reset(ulong start) {
    if(start >= G.Size()) {
        throw(std::out_of_range("Start Element is out of bounds!!\n(while resetting)"));
    }
    while(!toVisit.empty()) {toVisit.pop();}
    Init();
    Colors[start] = 'b';
    toVisit.push(start);
    cur = start;
}

/* ***** */

template<typename Data>
void PreOGIOnline<Data>::Init() noexcept {
    Colors.resize(G.Size(), 'w');
}
}