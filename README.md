# C-Logger

# Can be easily added by
> #include "log.h"


# usage
~~~
Log.info("this is main");
Log.info("this is logger");
Log.debug("printf has been executed here");
Log.errori("a should less than 3, a:", a);
~~~

# result screen shot
<img src="https://github.com/penguin418/C-Logger/blob/master/screenshot.jpg?raw=true" width="90%"></img>

# log level
~~~
VERBOSE
INFO
DEBUG
WARN
ERROR
~~~

# interface
## logging example
~~~
Log.debug(char* 태그);
Log.debugi(char* 태그, int 변수);
Log.debugf(char* 태그, float 변수);
Log.debugs(char* 태그, char* 메시지);
~~~
## set minimum logging level
~~~
Log.setLevel(VERBOSE);


