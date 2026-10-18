#include "fifo.h"

void fifo_worker_handler(
    QueueHandle_t requests,
    QueueHandle_t results,
    int id
)
{
    struct request_msg data;

    for (;;)
    {
        // Wait for a request from the task queue.
        if (xQueueReceive(requests, &data, portMAX_DELAY) == pdTRUE)
        {
            // Perform the required calculation.
            data.output = data.input + 5;

            // Record which worker handled the request.
            data.handled_by = (uint32_t)id;

            // Send the completed result to the supervisor.
            xQueueSendToBack(results, &data, portMAX_DELAY);
        }
    }
}