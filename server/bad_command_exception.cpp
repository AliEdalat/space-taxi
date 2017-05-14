#include "bad_command_exception.h"

using namespace std;

bad_command_exception::bad_command_exception(string _exception){
	exception=_exception;
}