inherit ROOM;


void create()
{
        set("short", "������");
        set("long", @LONG
�����ź�����٤���ϡ������ǽ����£�������һ��С������������
��������Զ�ۿɼ������������С���Žࣻ�²���Ȫ���峺�羵�����Թ���
����;�����ԡ֮�ã��Թž��С����ɻᡱ�����ơ����Ź��٤�ӣ�������
һ��ʯ����ֱͨɽ�ϡ�
LONG
        );

        set("exits", ([
		"westdown" : __DIR__"fuhusi",
		"northup" : __DIR__"shifang",
               ]));

        set("coor/x",-40);
	set("coor/y",-50);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-50);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-50);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}