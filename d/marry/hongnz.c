// hongniangzhuang.c

inherit ROOM;
void create()
{ 
	set("short", "����ׯ");
	set("long", @LONG
����������صĺ���ׯ�����źܴ�����ã����õĸ����ûʡ�
���������ϵ���������ǰ���Ǵ���ϲ�֡�ǰ�������㰸����
�������¯��¯���������̴�㡣¯�߷���һ�Ժ����㰸ǰ��
��һ�����Ŷ�����ԧ��Ϸˮ��ͼ�����������źܶ��Բ����ż��
��һ����Ѿ�ߴ������߹�ȥ��
LONG
); 
	set("objects", ([
		"/d/marry/mafu.c" : 1,
	]));

	set("no_fight",1);
	set("no_yun",1);
	set("no_beg",1);
	set("no_steal",1);

	setup();
	replace_program(ROOM); 
}