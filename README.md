# C-Logger

쉽게 추가할 수 있음
> #include "log.h"


다음과 같이 사용
~~~
Log.info("this is main");
Log.info("this is logger");
Log.debug("printf has been executed here");
Log.errori("a should less than 3, a:", a);
~~~
다음처럼 출력됨

<img src="https://github.com/penguin418/C-Logger/blob/master/screenshot.jpg?raw=true" width="90%"></img>


인터페이스 종류
~~~
Log.debug(char* 태그);
Log.debugi(char* 태그, int 변수);
Log.debugf(char* 태그, float 변수);
Log.debugs(char* 태그, char* 메시지);
~~~

로그레벨
~~~
verbose
info
debug
warn
error
~~~
