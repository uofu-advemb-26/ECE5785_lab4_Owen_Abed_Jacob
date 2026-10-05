#include <FreeRTOS.h>
#include <semphr.h>

#include "signaling.h"

void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data){

    if(uxSemaphoreGetCount(request, portMAX_DELAY) == 1){

        xSemaphoreTake(response, portMAX_DELAY);s
        
        *data = *data + 5;
        

    } else {

        xSemaphoreGive(response);
    
    }

}

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data){

    xSemaphoreTake(request, portMAX_DELAY);

    




}
