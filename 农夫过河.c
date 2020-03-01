#include <stdio.h>

typedef int DataType;

struct Queue
{
	int Max;
	int f;
	int r;
	DataType* elem;
};

typedef struct Queue* SeqQueue;


SeqQueue SetNullQueue_seq(int m)  //����һ���ն���
{
	SeqQueue squeue;
	squeue = (SeqQueue)malloc(sizeof(struct Queue));
	if (squeue == NULL)
	{
		printf("Alloc failure\n");
		return NULL;
	}
	squeue->elem = (int*)malloc(sizeof(DataType) * m);
	if (squeue->elem != NULL)
	{
		squeue->Max = m;
		squeue->f = 0;
		squeue->r = 0;
		return squeue;
	}

}

int IsNullQueue_seq(SeqQueue squeue)  //�п�
{
	return (squeue->f == squeue->r);
}

void EnQueue_seq(SeqQueue squeue, DataType x) //���
{
	if ((squeue->r + 1) % squeue->Max == squeue->f)
		printf("It is FULL Queue!");
	else
	{
		squeue->elem[squeue->r] = x;
		squeue->r = (squeue->r + 1) % (squeue->Max);
	}
}

void DeQueue_seq(SeqQueue squeue) //����
{
	if (IsNullQueue_seq(squeue))
		printf("It is empty queue!\n");
	else
		squeue->f = (squeue->f + 1) % (squeue->Max);
}


DataType FrontQueue_seq(SeqQueue squeue) //ȡ��ͷԪ��
{
	if (squeue->f == squeue->r)
	{
		printf("It is empty queue!\n");
	}
	else
		return (squeue->elem[squeue->f]);

}

int FaermerOnRight(int status)  //�ж�ũ���λ��
{
	return (0 != (status & 0x08));
}

int WorfOnRight(int status)     //�ж��ǵ�λ��
{
	return (0 != (status & 0x04));
}

int CabbageOnRight(int status)   //�жϰײ˵�λ��
{
	return (0 != (status & 0x02));
}

int GoatOnRight(int status)      //�ж����λ��
{
	return (0 != (status & 0x01));
}

int IsSafe(int status)  //�ж��Ƿ�ȫ
{
	if ((GoatOnRight(status) == CabbageOnRight(status)) && (GoatOnRight(status) != FaermerOnRight(status)))
		return (0);
	if ((GoatOnRight(status) == WorfOnRight(status)) && (GoatOnRight(status) != FaermerOnRight(status)))
		return 0;
	return 1;
}

void FarmerRiver()
{
	int i, movers, nowstatus, newstatus;
	int status[16];
	SeqQueue moveTo;
	moveTo = SetNullQueue_seq(20);
	EnQueue_seq(moveTo, 0x00);
	for (i = 0; i < 16; i++)
	{
		status[i] = -1;
	}
	status[0] = 0;

	while (!IsNullQueue_seq(moveTo) && (status[15] == -1))
	{
		nowstatus = FrontQueue_seq(moveTo);
		DeQueue_seq(moveTo);
		for (movers = 1; movers <= 8; movers <<= 1)
		{
			if ((0 != (nowstatus & 0x08)) == (0 != (nowstatus & movers)))
			{
				newstatus = nowstatus ^ (0x08| movers);
				if (IsSafe(newstatus) && (status[newstatus] == -1))
				{
					status[newstatus] = nowstatus;
					EnQueue_seq(moveTo, newstatus);
				}
			}
		}
	}
	if (status[15] != -1)
	{
		//printf("The reverse path is:\n");
		for (nowstatus = 15; nowstatus >= 0; nowstatus = status[nowstatus])
		{
			//printf("The nowstatus is : %d\t", nowstatus);

			Display_result(nowstatus);
			if (nowstatus == 0)
				return;
		}
	}
	else
		printf("No solution.\n");
}



void Display_result(int nowstatus)
{
	int i;
	int nothere[5];
	for (i = 0; i < 5; i++)
	{
		nothere[i] = 1;
	}
	printf("����:");
	if (nowstatus & 0x01)
	{
		printf(" ��  ");
		nothere[0] = 0;
	}

	if (nowstatus & 0x02)
	{
		printf(" �ײ� ");
		nothere[1] = 0;
	}
	if (nowstatus & 0x04)
	{
		printf(" ��  ");
		nothere[2] = 0;
	}

	if (nowstatus & 0x08)
	{
		printf(" ũ�� ");
		nothere[3] = 0;
	}

	printf("///////////////�ϰ�:");
	if(nothere[0])
		printf(" ��  ");
	if (nothere[1])
		printf(" �ײ� ");
	if (nothere[2])
		printf(" ��  ");
	if (nothere[3])
		printf(" ũ�� ");
	printf("\n");
}

int main(void)
{
	FarmerRiver();
	return 0;
}
