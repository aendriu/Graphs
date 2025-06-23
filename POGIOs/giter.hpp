namespace POGIO {

template<typename Data>
class Giter {
    public:
        virtual ~Giter() = default;

        virtual bool isTerminated() const noexcept = 0;
        virtual const Data& operator*() const = 0;
        virtual Giter& operator++() = 0;    
        virtual void Reset(ulong) = 0;
    protected:


};


}
    