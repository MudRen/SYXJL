inherit ROOM;

void create()
{
        set("short", "�����");
        set("long",@LONG
����ͨ�������º��µ��Ż������ͷ�������ϣ�ֻ��ͭ�ż����ѱ���
̤�����������������֮ʢ�ˡ�̧ͷ���Ͽ����������ɽ�������졣
LONG
        );
	set("outdoors","tianlongsi");
        set("exits", ([
		"south": __DIR__"wuchangge",
		"north": __DIR__"wuwoge",
	]));
        set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",10);
	set("coor/x",10);
	set("coor/y",-90);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
