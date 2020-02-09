//
// ArrayQueue Header.
//
// Made by (CE) TimetoTreatment.
//
#ifndef EARRAYQUEUE_H
#define EARRAYQUEUE_H


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Define DATA type and ArrayQueue structure
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

typedef int DATA;
// ~def ___ DATA;

typedef struct _ArrayQueue
{
	DATA* item;
	int front;
	int rear;
	int size;
	int max;

} AQueue;


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// ArrayQueue Functions
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

/* Queue initialize */
void AQiniti(AQueue* qu, int max);

/* Check whether empty */
int AQisEmpty(AQueue* qu);

/* Check whether full */
int AQisFull(AQueue* qu);

/* Insert DATA */
void AQpush(AQueue* qu, DATA data);

/* Extract DATA */
DATA AQpop(AQueue* qu);

/* Read front */
DATA AQpeek(AQueue* qu);

/* Read current Stack size */
int AQsize(AQueue* qu);

/* Show all DATA */
void AQlist(AQueue* qu);


#endif