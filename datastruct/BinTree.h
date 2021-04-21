//#ifndef __BINTREE_H__
//#define __BINTREE_H__
//#include "Sysutil.h"
//#include "Queue.h"
//#include "LinkStack.h"
//
//typedef char DataType;
//
//typedef struct BTNode
//{
//	DataType data;
//	struct BTNode* left;
//	struct BTNode* right;
//}BTNode;
//typedef BTNode* BinTree;
//
//void BinTreeCreat(BinTree* bt);//��������1
//BinTree BinTreeCreat_1(const char* str, int* i);//��������2
//BinTree BinTreeCreat_2();//��������3
//void PreOrder(BinTree bt);//�ݹ��������
//void InOrder(BinTree bt);//�ݹ��������
//void PostOrder(BinTree bt);//�ݹ�������
//size_t Height(BinTree bt);//����
//BTNode* Find(BinTree bt, DataType key);//����
//BinTree Clone(BinTree bt);//����¡
//BTNode* Parent(BinTree bt, BTNode* key);//���ڵ����
//bool Euqal(BinTree bt1, BinTree bt2);//��ͬ��Ƚ�
//void LevelOrder(BinTree bt);//��α���
//void PreOrderStack(BinTree bt);//�ǵݹ��������
//void InOrderStack(BinTree bt);//�ǵݹ��������
//void PostOrderStack(BinTree bt);//�ǵݹ�������
//BinTree BinTreeCreat_VLR_LVR(const char* vlr, const char* lvr, int n);//ǰ�������ָ���
//BinTree BinTreeCreat_LVR_LRV(const char* lvr, const char* lrv, int n);//����ͺ���ָ���
//int BinTreeSize(BTNode* root);//���Ľڵ���Ŀ
//int BinTreeLeafSize(BTNode* root);//����Ҷ����Ŀ
//int BinTreeComplete(BTNode* root);//������ȫ���룿
//int BinTreeLevelKSize(BTNode* root, int k);//���ĵ�K��ڵ���Ŀ
//
//void BinTreeCreat(BinTree* bt)
//{
//	DataType item;
//	scanf("%c", &item);
//	if ('#' == item)
//		*bt = NULL;
//	else {
//		*bt = (BTNode*)malloc(sizeof(BTNode));
//		if (*bt) {
//			(*bt)->data = item;
//			BinTreeCreat(&((*bt)->left));
//			BinTreeCreat(&((*bt)->right));
//		}
//	}
//}
//BinTree BinTreeCreat_1( const char* str,int *i)
//{
//	if (str[*i] == '#' || str[*i] == '\0')
//		return NULL;
//	else {
//		BTNode* p = (BTNode*)malloc(sizeof(BTNode));
//		if (p) {
//			p->data = str[*i];
//			(*i)++;
//			p->left = BinTreeCreat_1(str, i);
//			(*i)++;
//			p->right = BinTreeCreat_1(str, i);
//			return p;
//		}
//	}
//}
//BinTree BinTreeCreat_2()
//{
//	DataType item;
//	scanf("%c", &item);
//	if ('#' == item)
//		return  NULL;
//	else {
//		BTNode *bt = (BTNode*)malloc(sizeof(BTNode));
//		if (bt) {
//			bt->data = item;
//			bt->left = BinTreeCreat_2();
//			bt->right = BinTreeCreat_2();
//			return bt;
//		}
//	}
//}
//void PreOrder(BinTree bt)
//{//�������
//	if (bt) {
//		printf("%c ",bt->data);
//		PreOrder(bt->left);
//		PreOrder(bt->right);
//	}
//}
//void InOrder(BinTree bt)
//{
//	if (bt) {
//		InOrder(bt->left);
//		printf("%c ",bt->data);
//		InOrder(bt->right);
//	}
//}
//void PostOrder(BinTree bt)
//{
//	if (bt) {
//		PostOrder(bt->left);
//		PostOrder(bt->right);
//		printf("%c ", bt->data);
//	}
//}
//size_t Height(BinTree bt)
//{
//	if (!bt)
//		return 0;
//	else {
//		int h_left = Height(bt->left) + 1;
//		int h_right = Height(bt->right) + 1;
//		return h_left > h_right ? h_left : h_right;//˭���˭
//	}
//}
//BTNode* Find(BinTree bt,DataType key)
//{
//	if (bt == NULL || bt->data == key)//�ҵ�
//		return bt;
//	BTNode* p = Find(bt->left, key);
//	if (p)//��������
//		return p;
//	return Find(bt->right,key);
//}
//BTNode* Parent(BinTree bt, BTNode* key)
//{
//	if (!bt||bt==key)//����||���ڵ�
//		return NULL;
//	if (bt->left == key || bt->right == key)//��||�Һ��Ӿ���key
//		return bt;
//	BTNode* p = Parent(bt->left,key);//�����ǣ������ǰ��
//	if (p)//�������ҵ�
//		return p;
//	return Parent(bt->right,key);//��������
//}
//BinTree Clone(BinTree bt)
//{
//	if (NULL == bt)//����
//		return bt;
//	else{
//		BTNode* new_t = (BTNode*)malloc(sizeof(BTNode));
//		if (NULL != new_t) {
//			new_t->data = bt->data;//�ڵ�����
//			new_t->left = Clone(bt->left);//��������
//			new_t->right = Clone(bt->right);//��������
//		}
//	}
//}
//bool Euqal(BinTree bt1, BinTree bt2)
//{
//	if (bt1 == bt2 && !bt1)//�������ǿ���
//		return true;
//	if (!bt1 || !bt2)//һ��NULL����һ����NULL
//		return false;
//	return (bt1->data == bt2->data) && Euqal(bt1->left, bt2->left) && Euqal(bt1->right, bt2->right);//ֵ��ͬ&&�������&&�������
//}
//void LevelOrder(BinTree bt)
//{//��α���
//	if (NULL != bt) {
//		Queue Q;
//		QueueInit(&Q);
//		QueuePush(&Q, bt);//���ڵ����
//		while (!QueueEmpty(&Q)) {//���зǿ�
//			BTNode* p = QueueFront(&Q);//��ȡ��ͷԪ��
//			QueuePop(&Q);//����
//			printf("%c ",p->data);
//			if (p->left)//��������
//				QueuePush(&Q, p->left);
//			if (p->right)//��������
//				QueuePush(&Q, p->right);
//		}
//	}
//}
//void PreOrderStack(BinTree bt)
//{	//����������ǵݹ�
//	if (NULL != bt) {
//		LinkStack stack;
//		LinkStackInit(&stack);
//		LinkStackPush(&stack,bt);
//		while (!LinkStackEmpty(&stack)) {
//			BTNode* p = LinkStackTop(&stack);
//			LinkStackPop(&stack);
//			printf("%c ",p->data);
//			if (p->right)
//				LinkStackPush(&stack, p->right);
//			if (p->left)
//				LinkStackPush(&stack, p->left);
//		}
//	}
//}
//void InOrderStack(BinTree bt)
//{	//����������ǵݹ�
//	if (NULL != bt) {
//		LinkStack stack;
//		LinkStackInit(&stack);
//		BTNode* p = bt;
//		while (!LinkStackEmpty(&stack) || p){//ջδ��||������
//			while (p) {//p���ڽڵ㣬ѹջ
//				LinkStackPush(&stack, p);
//				p = p->left;
//			}
//			p = LinkStackTop(&stack);
//			LinkStackPop(&stack); //��ջ
//			printf("%c ", p->data);
//			p = p->right;//��������
//		}
//	}
//}
//void PostOrderStack(BinTree bt)
//{
//	//����������ǵݹ�
//	if (NULL != bt) {
//		LinkStack stack;
//		LinkStackInit(&stack);
//		BTNode* p, * pre = NULL;
//		while (!LinkStackEmpty(&stack) || bt) {//ջδ��||������
//			while (bt) {//p���ڽڵ㣬ѹջ
//				LinkStackPush(&stack, bt);
//				bt = bt->left;
//			}
//			p = LinkStackTop(&stack);
//			if (p->right == NULL || p->right == pre) {
//				printf("%c ", p->data);
//				LinkStackPop(&stack); //��ջ
//				pre = p;//ǰ������
//			}
//			else
//				bt = p->right;//��������
//		}
//	}
//}
//BinTree BinTreeCreat_VLR_LVR(const char* vlr,const char* lvr, int n)
//{
//	if (n == 0)//������û�����ݣ�˵����Ҷ�ڵ�ĺ���(������)������ֱ�ӷ���
//		return NULL;
//	int k = 0;
//	while (lvr[k] != vlr[0]) //��������Ѱ����ǰ��һ��������
//		k++;
//	BTNode* t = (BTNode*)malloc(sizeof(BTNode));//���ڵ㴴��
//	assert(t != NULL);
//	t->data = lvr[k];//���ڵ����ݷ���
//	t->left = BinTreeCreat_VLR_LVR(vlr + 1, lvr, k);//����������
//	t->right = BinTreeCreat_VLR_LVR(vlr + k + 1, lvr + k + 1, n - k - 1);//����������
//	return t;
//}
//BinTree BinTreeCreat_LVR_LRV(const char* lvr,const char* lrv, int n)
//{
//	if (n == 0)
//		return NULL;
//	int k = 0;
//	while (lvr[k] != lrv[n-1])
//		k++;
//	BTNode* t = (BTNode*)malloc(sizeof(BTNode));
//	assert(t != NULL);
//	t->data = lvr[k];
//	t->right = BinTreeCreat_LVR_LRV(lvr + k + 1, lrv + k, n - k - 1);
//	t->left = BinTreeCreat_LVR_LRV(lvr, lrv, k);
//	return t;
//}
//void BinTreeDestory(BinTree* bt)
//{
//	if(*bt){
//		BinTreeDestory(&((*bt)->left));
//		BinTreeDestory(&((*bt)->right));
//		free(*bt);
//		*bt = NULL;
//	}
//}
//int BinTreeSize(BTNode* root)
//{
//	if (NULL == root)
//		return 0;
//	return BinTreeSize(root->left) + BinTreeSize(root->right) + 1;
//}
//int BinTreeLeafSize(BTNode* root)
//{
//	if (NULL == root)
//		return 0;
//	if (NULL == root->left && NULL == root->right)
//		return 1;
//	return BinTreeLeafSize(root->left) + BinTreeLeafSize(root->right);
//}
//int BinTreeComplete(BTNode* root)
//{	//0��ʾ����
//	if (NULL == root)
//		return 1;
//	if (root->right && NULL == root->left)
//		return 0;
//	return BinTreeComplete(root->left) && BinTreeComplete(root->right);
//}
//int BinTreeLevelKSize(BTNode* root, int k)
//{//���ڵ���Ϊ��һ��
//	if (NULL == root || k <= 0)
//		return 0;
//	if (1 == k)
//		return 1;
//	return BinTreeLevelKSize(root->left, k - 1) + BinTreeLevelKSize(root->right, k - 1);
//}
//#endif 
//
