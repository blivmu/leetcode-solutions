class ProductOfNumbers {
public:

    // member vector variable for class
    vector<int> numVec;

    ProductOfNumbers() {
        numVec = {};    // initialize vector member as empty
    }
    
    void add(int num) {
        numVec.push_back(num);  // append "num" to end of vector array
    }
    
    int getProduct(int k) {

        // get the current last index of array (size - 1)
        int i = numVec.size() - 1;
        // initialize return var. to 1 (multiplication, and "k" is guaranteed to be 1 at min.)
        int product = 1;
        
        // loop through the last indices in array, k times, multiplying "product" by each index
        for(int j = 0; j < k; j++)
        {
            product *= numVec[i];
            i--;
        }

        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
