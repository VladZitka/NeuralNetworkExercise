#include "NeuralNetwork.hpp"

namespace Vlado
{
    NeuralNetwork::NeuralNetwork(std::vector<unsigned int> topology, Scalar learningRate) :
    topology(topology), learningRate(learningRate)
    {
        for(const auto& i : topology){
            //Initialize the neron layers
            if (i == topology.back()) neuronLayers.push_back(std::make_unique<RowVector>(i));
            else neuronLayers.push_back(std::make_unique<RowVector>(i+1));
            
            //Initialize cache and delta vectors
            cacheLayers.push_back(std::make_unique<RowVector>(neuronLayers.size()));
            deltas.push_back(std::make_unique<RowVector>(neuronLayers.size()));

            // get a handle on a reference of value at the recently added element by
            // using coeffRef() on a vector.back()
            if (i != topology.back()) {
                neuronLayers.back()->coeffRef(i) = 1.0;
                cacheLayers.back()->coeffRef(i) = 1.0;
            }
        }

        //initialize weights
        for(size_t i =0; i < topology.size(); i++ ){
            if(i > 0){
                if (i != topology.size() - 1){
                    weights.push_back(
                        std::make_unique<Matrix>(Matrix(topology[i-1]+1, topology[i]+1))
                        );
                    weights.back()->setRandom();
                    weights.back()->col(topology[i]).setZero();
                    weights.back()->coeffRef(topology[i-1],topology[i]) = 1.0;
                }
                else{
                    weights.push_back(
                        std::make_unique<Matrix>(Matrix(topology[i-1]+1, topology[i]))
                    );
                    weights.back()->setRandom();
                }
            }
        }
    };
}