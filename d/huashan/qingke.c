// qingke.c

inherit ROOM;

void create()
{
	set("short", "���ƺ");
	set("long", @LONG
�߹���᫵�ʮ���̣��������ţ��͵������ƺ�����ƺ��һɽ�����
��������Ϊƽ̹�������￪ʼ����ɽ��·������ԭ�������ʯ�ס�������
��ʯ��·����ʯ��������ʯ������ȥɽ�����գ��ο����ˣ��͸û�ͷ�ˡ�
ԶԶ����һ��ССʯͤ�����Ƕ���ͤ�ˡ��ഫ��̫���뻪��������������
�ˣ�����ɽ��Ϊ��ע����̫�����ˣ��Ӵ˻�ɽ�ϵ����ؾͲ������Ǯ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"shaluo",
		"eastup" : __DIR__"qianchi",
	]));
	set("no_clean_up", 0);
        set("outdoors", "��ɽ");

	set("coor/x",50);
	set("coor/y",120);
	set("coor/z",10);
	set("coor/x",50);
	set("coor/y",120);
	set("coor/z",10);
	set("coor/x",50);
	set("coor/y",120);
	set("coor/z",10);
	set("coor/x",50);
	set("coor/y",120);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
 
