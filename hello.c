#include <emscripten.h>
#include <math.h>
#include <stdlib.h>


EMSCRIPTEN_KEEPALIVE
void computeSineOfRandomDegree () {
    /*
    *   Getting this random double was grabbed
    *   from the internet :)
    */
    double range = (360-0);
    double divNum = RAND_MAX / range;
    double degree = 0 + (rand() / divNum);
    double sineInRads = sin(degree);
    EM_ASM_({
        var element = document.getElementById('put-num-here');
        element.innerText = 'The randomly generated degree was: ' + $0 +' In radians this is: ' + $1;
    }, degree, sineInRads);
}