namespace graphs {
 

// Default Costructor
template<typename Data>
AdjMatrix<Data>::AdjMatrix() : elements(3), matrix(3, vector<Data>(3, 0)) {
    vcard = 3;
}

    
// Constructor
    
template<typename Data>
AdjMatrix<Data>::AdjMatrix(ulong size) : elements(size), matrix(size, vector<Data>(size, 0)) {
    vcard = size;
}


// Destructor


// Copy Costructor
template<typename Data>
AdjMatrix<Data>::AdjMatrix(const AdjMatrix& other) {
    this->vcard = other.vcard;
    this->elements = other.elements;
    this->matrix = other.matrix;
}


// Move Costructor
template<typename Data>
AdjMatrix<Data>::AdjMatrix(AdjMatrix&& other) noexcept {
    
    this->vcard = other.vcard;
    this->elements = std::move(other.elements);
    this->matrix = std::move(other.matrix);
    
    other.vcard = 0;
    other.elements.clear();
    other.matrix.clear();

}

// Copy Assignement
template<typename Data>
AdjMatrix<Data>& AdjMatrix<Data>::operator=(const AdjMatrix& other) {
    
    this->vcard = other.vcard;
    this->elements = other.elements;
    this->matrix = other.matrix;

    return *this;
}

// Move Assignment
template<typename Data>
AdjMatrix<Data>& AdjMatrix<Data>::operator=(AdjMatrix&& other) noexcept {
    
    this->vcard = other.vcard;
    this->elements = std::move(other.elements);
    this->matrix = std::move(other.matrix);

    other.vcard = 0;
    other.elements.clear();
    other.matrix.clear();

    return *this;
}

// op[]
template<typename Data>
Data& AdjMatrix<Data>::operator[](const ulong pos) {
    return elements[pos];
}

template<typename Data>
const Data& AdjMatrix<Data>::operator[](const ulong pos) const {
    return elements[pos];
}

// Specific member functions
template<typename Data>
void AdjMatrix<Data>::addLink(ulong src, ulong dest) {
    matrix[src][dest] = 1;
}

template<typename Data>
void AdjMatrix<Data>::removeLink(ulong src, ulong dest) {
    matrix[src][dest] = 0;
}

template<typename Data>
bool AdjMatrix<Data>::hasLink(ulong src, ulong dest) const {
    return ( matrix[src][dest] == 1 );
}

template<typename Data>
void AdjMatrix<Data>::setElements(vector<Data>& vec) {
    elements = vec;
}




// utils

template<typename Data>
void AdjMatrix<Data>::PrintAdjMatInfo() const noexcept {
    std::cout << "elements : ";
    for(const auto& el : elements) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    std::cout << "   ";
    for(const auto& el : elements) {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    for(ulong row = 0; row < vcard; row++) {
        std::cout << elements[row] << "| ";
        for(ulong col = 0; col < vcard; col++) {
            std::cout << elements[col] << "(" << matrix[row][col] << ") ";
        }
        std::cout << std::endl;
    }
}


template<typename Data>
void AdjMatrix<Data>::Randomize(ulong num_el) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> size_dist(1, num_el); // Numero di nodi tra 1 e num_el
    std::uniform_int_distribution<Data> value_dist(1, 100); // Valori casuali tra 1 e 100
    std::bernoulli_distribution link_dist(0.3); // Probabilità di collegamento

    ulong n = size_dist(gen);

    // Ridimensiona e genera elementi casuali
    elements.resize(n);
    for (auto& el : elements)
        el = value_dist(gen);

    // Ridimensiona la matrice
    matrix.assign(n, std::vector<Data>(n, 0));
    vcard = n;

    // Connessioni casuali (no self-loop)
    for (ulong i = 0; i < n; ++i) {
        for (ulong j = 0; j < n; ++j) {
            if (i != j) {
                if (link_dist(gen))
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}


/* ***** */
template<typename Data>
ulong AdjMatrix<Data>::Size() const noexcept {
    return this->vcard;
}

}