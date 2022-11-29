#include <stdio.h>
#include <assert.h>
#define DEFAULT_STUB_VALUE 200
#define DEFAULT_INTEGRATION_ENV 1
#define DEFAULT_TEST_ENV 2

int alertFailureCount = 0;
int Current_Env = DEFAULT_INTEGRATION_ENV;


int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode;
    if(Current_Env == DEFAULT_INTEGRATION_ENV)
    {
         returnCode = celcius;
    }
    else
    {
         returnCode = networkAlertStub(celcius);
    }
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    assert(alertInCelcius(500) == 1); 
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
