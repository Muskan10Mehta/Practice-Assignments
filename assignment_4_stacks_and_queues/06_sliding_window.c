/**
 * Program for this ques: You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
 * You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 * Return the max sliding window.
 *
 * Coded on leetcode
 *
 * @Muskan, 1910990681, 15/08/2021
 * Assignment 4 Stacks and Queues, Question 6
 * Resources: Geeksforgeeks(for struct)
 */

typedef struct {
    int head;
    int tail;
    int size;
    int *array;

} Queue;

Queue* createQueue(){
    Queue *queue = (Queue *) malloc (sizeof(Queue));
    queue->head = 0;
    queue->tail = -1;
    queue->size = 100000;
    queue->array = (int *) malloc(queue->size * sizeof(int));

    return queue;
}

void push(Queue* rs, int val){

    if(!(rs->tail >= rs->size)){
        rs->tail = rs->tail + 1;
        rs->array[rs->tail] = val;
    }
}

int pop(Queue* rs){

    int i = 0;
    int val = 0;
    val = rs->array[rs->head];

    for(i = 0; i <= rs-> tail; i++){
            rs->array[i] = rs->array[i + 1];
    }

    rs->tail--;

    return val;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){

    int max_num = 0, temp_num = 0;
    int i = 0, j = 0, m = 0;
    int counterk = 0;

    *returnSize = numsSize - k + 1;

    int *max = (int *) malloc (*returnSize * sizeof(int));
    Queue* rs = createQueue();

    while(i < numsSize){

        push(rs, nums[i]);
        counterk++;
        i++;

        if(counterk == k){

            counterk = 0;
            max_num = pop(rs);
            i = i - k + 1;

            for(j = 1; j < k; j++){
                temp_num = pop(rs);
                if(max_num < temp_num){
                    max_num = temp_num;
                }
            }

            max[m] = max_num;
            m++;
        }

    }
    return max;
}
 

