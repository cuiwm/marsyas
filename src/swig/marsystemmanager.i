
/* Headers for classes used here */
%{
#include <marsyas/MarSystemManager.h>

using namespace Marsyas;

%}

%include "std_vector.i"
%include "std_string.i"

namespace std {
        %template(Vector_String) vector<string>;
};

class MarSystemManager {
        public:
                MarSystemManager(); // Enable Constructor

                /* Create a MarSystem of a given <type> having the given <name>. */
                MarSystem *create(std::string,std::string);

                /* Get a list of all prototypes in this MarSystemManager */
                std::vector<std::string> registeredPrototypes();
};


