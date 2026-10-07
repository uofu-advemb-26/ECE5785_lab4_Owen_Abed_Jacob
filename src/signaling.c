#include <FreeRTOS.h>
#include <semphr.h>

#include "signaling.h"

void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data){

    if(uxSemaphoreGetCount(request, 100) == 1){

        xSemaphoreTake(response, 100);
        
        data->output = data->input + 5;
        

    } else {

        xSemaphoreGive(response);
    
    }

}

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data){

    if(xSemaphoreTake(request, 100) == pdFALSE){
        return pdFALSE;
    }

    if(xSemaphoreGetCount(response, 1000))
    

    return pdTRUE;

}
