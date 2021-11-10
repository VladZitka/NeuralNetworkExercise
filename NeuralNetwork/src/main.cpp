#include "NeuralNetwork.cpp"

 
int main()
{
    Vlado::NeuralNetwork NN = Vlado::NeuralNetwork({2,3,1});

  NN.printPrivateVariables();

  return 0;
}