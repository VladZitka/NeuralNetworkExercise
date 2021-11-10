#include <iostream>
#include <vector>
#include <memory>
#include <eigen3/Eigen/Eigen>

namespace Vlado {

    // Aliases for types using typedef for naming convention
    typedef float Scalar;
    typedef Eigen::MatrixXf Matrix;
    typedef Eigen::RowVectorXf RowVector;
    typedef Eigen::VectorXf ColVector;


    // Class Neural Network 
    class NeuralNetwork {
        public:
        //Constructor
        NeuralNetwork(std::vector<unsigned int> topology, Scalar learningRate = Scalar(0.005)); 

        // method propagating the data forward
        void propagateForward(RowVector& input);

        // method probagating the data backwards
        void propagateBackward(RowVector& output);

        // method calculating errors made by neurons in each layer
        void calcErros(RowVector& output);

        // mehtod to update the weights of connections between neurons
        void updateWeights();


        // method to train the NeuralNetwork on given array of data points
        void train(std::vector<std::unique_ptr<RowVector>> data);

        void printPrivateVariables(){
            printVector("neuronLayers", neuronLayers);
            printVector("cacheLayers",cacheLayers);
            printVector("deltas",deltas);
            printMatrix("weights", weights);
            
            std::cout << "learningRate: \n" << learningRate << std::endl; 

            std::cout << "topology: \n" ;
            for(auto const& i: topology) std::cout << i << " ";
            std::cout << std::endl;

        };
        

        private:
        // Storage variables for working with the Neural Network
            // storage of different layers of the NN
            std::vector<std::unique_ptr<RowVector>> neuronLayers;
            // storage of the unactivated (activation method not yet applied) values of layers
            std::vector<std::unique_ptr<RowVector>> cacheLayers; 
            // storage of error contribution of each neuron
            std::vector<std::unique_ptr<RowVector>> deltas;
            // storage of the connection weights
            std::vector<std::unique_ptr<Matrix>> weights;
            Scalar learningRate;
            std::vector<unsigned int> topology;
        // private methods
            void printVector(std::string name, const std::vector<std::unique_ptr<RowVector>> &layers){
            std::cout << name << std::endl;
                for (const auto& layer: layers){
                    std::cout << *layer << std::endl;
                }
                std::cout << std::endl;
            };

            void printMatrix(std::string name, const std::vector<std::unique_ptr<Matrix>> &matrices){
                std::cout << name << std::endl;
                for (const auto& matrix: matrices){
                    std::cout<< *matrix << std::endl;
                }
                std::cout << std::endl;
            };

    };



}