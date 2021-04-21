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
//void BinTreeCreat(BinTree* bt);//创建方法1
//BinTree BinTreeCreat_1(const char* str, int* i);//创建方法2
//BinTree BinTreeCreat_2();//创建方法3
//void PreOrder(BinTree bt);//递归先序遍历
//void InOrder(BinTree bt);//递归中序遍历
//void PostOrder(BinTree bt);//递归后序遍历
//size_t Height(BinTree bt);//树深
//BTNode* Find(BinTree bt, DataType key);//查找
//BinTree Clone(BinTree bt);//树克隆
//BTNode* Parent(BinTree bt, BTNode* key);//父节点查找
//bool Euqal(BinTree bt1, BinTree bt2);//树同异比较
//void LevelOrder(BinTree bt);//层次遍历
//void PreOrderStack(BinTree bt);//非递归先序遍历
//void InOrderStack(BinTree bt);//非递归中序遍历
//void PostOrderStack(BinTree bt);//非递归后序遍历
//BinTree BinTreeCreat_VLR_LVR(const char* vlr, const char* lvr, int n);//前序和中序恢复树
//BinTree BinTreeCreat_LVR_LRV(const char* lvr, const char* lrv, int n);//中序和后序恢复树
//int BinTreeSize(BTNode* root);//树的节点数目
//int BinTreeLeafSize(BTNode* root);//树的叶子数目
//int BinTreeComplete(BTNode* root);//树是完全树码？
//int BinTreeLevelKSize(BTNode* root, int k);//树的第K层节点数目
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
//{//先序输出
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
//		return h_left > h_right ? h_left : h_right;//谁深返回谁
//	}
//}
//BTNode* Find(BinTree bt,DataType key)
//{
//	if (bt == NULL || bt->data == key)//找到
//		return bt;
//	BTNode* p = Find(bt->left, key);
//	if (p)//左树存在
//		return p;
//	return Find(bt->right,key);
//}
//BTNode* Parent(BinTree bt, BTNode* key)
//{
//	if (!bt||bt==key)//空树||根节点
//		return NULL;
//	if (bt->left == key || bt->right == key)//左||右孩子就是key
//		return bt;
//	BTNode* p = Parent(bt->left,key);//都不是，向深度前进
//	if (p)//在左树找到
//		return p;
//	return Parent(bt->right,key);//在右树找
//}
//BinTree Clone(BinTree bt)
//{
//	if (NULL == bt)//空树
//		return bt;
//	else{
//		BTNode* new_t = (BTNode*)malloc(sizeof(BTNode));
//		if (NULL != new_t) {
//			new_t->data = bt->data;//节点数据
//			new_t->left = Clone(bt->left);//左树复制
//			new_t->right = Clone(bt->right);//右树复制
//		}
//	}
//}
//bool Euqal(BinTree bt1, BinTree bt2)
//{
//	if (bt1 == bt2 && !bt1)//两个都是空树
//		return true;
//	if (!bt1 || !bt2)//一个NULL，另一个非NULL
//		return false;
//	return (bt1->data == bt2->data) && Euqal(bt1->left, bt2->left) && Euqal(bt1->right, bt2->right);//值相同&&左树相等&&右树相等
//}
//void LevelOrder(BinTree bt)
//{//层次遍历
//	if (NULL != bt) {
//		Queue Q;
//		QueueInit(&Q);
//		QueuePush(&Q, bt);//根节点入队
//		while (!QueueEmpty(&Q)) {//队列非空
//			BTNode* p = QueueFront(&Q);//获取队头元素
//			QueuePop(&Q);//出队
//			printf("%c ",p->data);
//			if (p->left)//左树遍历
//				QueuePush(&Q, p->left);
//			if (p->right)//右树遍历
//				QueuePush(&Q, p->right);
//		}
//	}
//}
//void PreOrderStack(BinTree bt)
//{	//先序遍历，非递归
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
//{	//中序遍历，非递归
//	if (NULL != bt) {
//		LinkStack stack;
//		LinkStackInit(&stack);
//		BTNode* p = bt;
//		while (!LinkStackEmpty(&stack) || p){//栈未空||树不空
//			while (p) {//p存在节点，压栈
//				LinkStackPush(&stack, p);
//				p = p->left;
//			}
//			p = LinkStackTop(&stack);
//			LinkStackPop(&stack); //出栈
//			printf("%c ", p->data);
//			p = p->right;//进入右树
//		}
//	}
//}
//void PostOrderStack(BinTree bt)
//{
//	//后序遍历，非递归
//	if (NULL != bt) {
//		LinkStack stack;
//		LinkStackInit(&stack);
//		BTNode* p, * pre = NULL;
//		while (!LinkStackEmpty(&stack) || bt) {//栈未空||树不空
//			while (bt) {//p存在节点，压栈
//				LinkStackPush(&stack, bt);
//				bt = bt->left;
//			}
//			p = LinkStackTop(&stack);
//			if (p->right == NULL || p->right == pre) {
//				printf("%c ", p->data);
//				LinkStackPop(&stack); //出栈
//				pre = p;//前驱更新
//			}
//			else
//				bt = p->right;//进入右树
//		}
//	}
//}
//BinTree BinTreeCreat_VLR_LVR(const char* vlr,const char* lvr, int n)
//{
//	if (n == 0)//该子树没有数据，说明是叶节点的孩子(不存在)，所以直接返回
//		return NULL;
//	int k = 0;
//	while (lvr[k] != vlr[0]) //在中序中寻找与前序一样的数据
//		k++;
//	BTNode* t = (BTNode*)malloc(sizeof(BTNode));//父节点创建
//	assert(t != NULL);
//	t->data = lvr[k];//父节点数据放入
//	t->left = BinTreeCreat_VLR_LVR(vlr + 1, lvr, k);//创建左子树
//	t->right = BinTreeCreat_VLR_LVR(vlr + k + 1, lvr + k + 1, n - k - 1);//创建右子树
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
//{	//0表示不是
//	if (NULL == root)
//		return 1;
//	if (root->right && NULL == root->left)
//		return 0;
//	return BinTreeComplete(root->left) && BinTreeComplete(root->right);
//}
//int BinTreeLevelKSize(BTNode* root, int k)
//{//根节点视为第一层
//	if (NULL == root || k <= 0)
//		return 0;
//	if (1 == k)
//		return 1;
//	return BinTreeLevelKSize(root->left, k - 1) + BinTreeLevelKSize(root->right, k - 1);
//}
//#endif 
//
