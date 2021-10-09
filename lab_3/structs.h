#include <iostream>
#include <vector>

namespace lab3 {
    struct carriage
    {
        int total_place;
        int free_place;
    };
    
    class Train
    {
    private:
        std::vector<carriage *> loco;
    public:
        Train();
        ~Train();
    };    
    

}