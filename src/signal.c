
#include "signaling.h"

void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data)
{
    // Wait until the requester signals the worker.
    if (xSemaphoreTake(request, portMAX_DELAY) == pdTRUE)
    {
        
        data->output = data->input + 5;

        // Signal that the calculation is complete.
        xSemaphoreGive(response);
    }
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data)
{
    // Send a request to the worker.
    if (xSemaphoreGive(request) != pdTRUE)
    {
        return pdFALSE;
    }

    // Wait for the worker to finish.
    if (xSemaphoreTake(response, 1000) == pdTRUE)
    {
        return pdTRUE;
    }

    // Return false if no response was received.
    return pdFALSE;
}
