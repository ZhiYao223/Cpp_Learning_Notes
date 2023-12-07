/*
	功能： 将数据进行链式存储
	链表：list是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针连接实现的
	链表的组成： 链表由一系列结点组成
	结点的组成：一个是存储数据元素的数据域， 另一个是存储下一个结点地址的指针域
	STL中的链表是一个双向循环链表

	由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器
	list的优点:
	采用动态存储分配，不会造成内存浪费和溢出
	链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
	list的缺点：
	链表灵活，但是空间(指针域)和时间(遍历）额外耗费较大

	list有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的
	

	总结：STL中list和vector是两个最常被使用的容器，各有优缺点

*/  
