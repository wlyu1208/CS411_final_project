import torch
import torch.nn as nn

class GRU(nn.Module):
    def __init__(self, input_size, hidden_size, output_size, model_type="gru", n_layers=1):
        super(GRU, self).__init__()
        """
        Initialize the RNN model.
        
        You should create:
        - An Embedding object which will learn a mapping from tensors
        of dimension input_size to embedding of dimension hidden_size.
        - Your RNN network which takes the embedding as input (use models
        in torch.nn). This network should have input size hidden_size and
        output size hidden_size.
        - A linear layer of dimension hidden_size x output_size which
        will predict output scores.

        Inputs:
        - input_size: Dimension of individual element in input sequence to model
        - hidden_size: Hidden layer dimension of RNN model
        - output_size: Dimension of individual element in output sequence from model
        - model_type: RNN network type can be "rnn" (for basic rnn), "gru", or "lstm"
        - n_layers: number of layers in your RNN network
        """
        
        self.model_type = model_type
        self.input_size = input_size
        self.hidden_size = hidden_size
        self.output_size = output_size
        self.n_layers = n_layers
        
        ####################################
        #          YOUR CODE HERE          #
        ####################################

        self.embedding = nn.Embedding(input_size, hidden_size)
#         self.gru = nn.GRU(input_size, hidden_size, n_layers)
        self.gru = nn.GRU(hidden_size, hidden_size, n_layers)
        self.fc1 = nn.Linear(hidden_size, 64)
        self.fc2 = nn.Linear(64, output_size)
        ##########       END      ##########
        


    def forward(self, input, hidden):
        """
        Forward pass through RNN model. Use your Embedding object to create 
        an embedded input to your RNN network. You should then use the 
        linear layer to get an output of self.output_size. 

        Inputs:
        - input: the input data tensor to your model of dimension (batch_size)
        - hidden: the hidden state tensor of dimension (n_layers x batch_size x hidden_size) 

        Returns:
        - output: the output of your linear layer
        - hidden: the output of the RNN network before your linear layer (hidden state)
        """
        
        ####################################
        #          YOUR CODE HERE          #
        ####################################
        batch_size = input.size(0)
#         new_input = self.embedding(input).view(self.n_layers, batch_size, self.input_size).cuda()
        new_input = self.embedding(input).view(1, batch_size, -1).cuda()
        #print("before self rnn: ", new_input.size())
        output, hidden = self.gru(new_input, hidden)
        output = output.contiguous().view(-1, self.hidden_size)
        output = self.fc1(output)
        output = self.fc2(output)
        ##########       END      ##########
        
        return output, hidden

    def init_hidden(self, batch_size, device=None):
        """
        Initialize hidden states to all 0s during training.
        
        Hidden states should be initilized to dimension (n_layers x batch_size x hidden_size) 

        Inputs:
        - batch_size: batch size

        Returns:
        - hidden: initialized hidden values for input to forward function
        """
                
        ####################################
        #          YOUR CODE HERE          #
        ####################################
        hidden = torch.zeros(self.n_layers, batch_size, self.hidden_size, requires_grad = True).cuda()

        ##########       END      ##########

        return hidden
