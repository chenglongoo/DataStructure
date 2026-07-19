## 单链表知识点

### 1. 结点定义
```cpp
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
```

说明：
- `LinkList` 表示链表头指针
- 下面默认都按“带头结点”的单链表来写

### 2. 初始化
```cpp
bool InitList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    if (L == nullptr) return false;
    L->next = nullptr;
    return true;
}
```

说明：
- 初始化后只有头结点，没有数据结点
- 头结点的 `next` 初始为 `nullptr`

### 3. 求表长
```cpp
int Length(LinkList L) {
    int len = 0;
    LNode *p = L->next;
    while (p != nullptr) {
        ++len;
        p = p->next;
    }
    return len;
}
```

时间复杂度：

```text
O(n)
```

### 4. 按序号查找
```cpp
// 返回第 i 个数据结点的地址，i 从 1 开始
LNode *GetElem(LinkList L, int i) {
    if (i < 1) return nullptr;

    LNode *p = L->next;
    int j = 1;
    while (p != nullptr && j < i) {
        p = p->next;
        ++j;
    }
    return p;
}
```

说明：
- `i = 1` 表示第一个数据结点
- 如果 `i` 不合法或超出表长，返回 `nullptr`

### 5. 按值查找
```cpp
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != nullptr && p->data != e) {
        p = p->next;
    }
    return p;
}
```

### 6. 插入结点
```cpp
// 在第 i 个位置插入元素 e，i 的合法范围是 1 <= i <= n + 1
bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1) return false;

    LNode *p = L;
    int j = 0;
    while (p != nullptr && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (p == nullptr) return false;

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == nullptr) return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
```

### 7. 删除结点
```cpp
// 删除第 i 个数据结点，并用 e 返回其值
bool ListDelete(LinkList &L, int i, ElemType &e) {
    if (i < 1) return false;

    LNode *p = L;
    int j = 0;
    while (p->next != nullptr && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (p->next == nullptr) return false;

    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
```

### 8. 头插法建立单链表
```cpp
LinkList List_HeadInsert(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    if (L == nullptr) return nullptr;
    L->next = nullptr;

    int x;
    LNode *s;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        if (s == nullptr) return L;
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
```

特点：
- 新结点总是插到最前面
- 输入顺序和链表中的实际顺序相反

### 9. 尾插法建立单链表
```cpp
LinkList List_TailInsert(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    if (L == nullptr) return nullptr;
    L->next = nullptr;

    LNode *r = L;
    LNode *s;
    int x;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        if (s == nullptr) return L;
        s->data = x;
        s->next = nullptr;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    return L;
}
```

特点：
- 新结点插到表尾
- 输入顺序和链表中的实际顺序一致

### 10. 记忆点
- 带头结点时，头结点不存数据
- 第 `i` 个数据结点，`i` 从 1 开始
- 查找、插入、删除都要先处理边界条件
- 单链表按位置访问是 `O(n)`
