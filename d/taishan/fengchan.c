// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
�����������ѡ��������������֮������·Ӣ�����ܼ�ѹȺ�ۣ�
�������������ʶ�������������Ϊͳ����ԭ���ֵ����䡣��̨��
�ڷ��ź����������������ڴ��������¡�̨�ϸ߸�����һ���죬
���飺�����е� �ĸ����֡� �������Ҹ���������λ������ʿ����
�߶�����һ���Ż�Ƥ���Σ�ʱ��������ǰ������ǰ���μ�������
LONG
	);

	set("exits", ([
		"down" : __DIR__"yuhuang",
		"east" : __DIR__"xiayi",
		"west" : __DIR__"zhengqi",
	]));

	set("objects",([
		"/clone/npc/meng-zhu" : 1,
		__DIR__"npc/wei-shi1" : 2,
	]));

//      set("no_clean_up", 1);
	set("outdoors", "taishan");

	set("coor/x",70);
	set("coor/y",130);
	set("coor/z",120);
	set("coor/x",70);
	set("coor/y",130);
	set("coor/z",120);
	set("coor/x",70);
	set("coor/y",130);
	set("coor/z",120);
	set("coor/x",70);
	set("coor/y",130);
	set("coor/z",120);
	setup();
        replace_program(ROOM);
}
