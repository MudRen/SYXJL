inherit ROOM;
 
void create()
{
        set("short", "��ʯ��");
        set("long",@LONG
����̫������һ�������ϵ�ʯ�ţ�վ�����ϣ�ǧ����澡
����ǰ�����ɵ��Ŀ���������ȴ�˷��ա��ŵ������Ǻܴ��һ
Ƭׯ԰��
LONG );
        set("exits", ([
  "east" : __DIR__"hubinlu1",
  "west" : __DIR__"zhangqian",
]));
        set("outdoors", "taohua");
 
        set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}
