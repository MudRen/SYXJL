// Room: diecong3.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������վ��һ���������....����һ������....���Ǻ����ͻ�
��....������������Ƣ�Ļ��ķҷ�....��ï�ܵĻ����ڱ��˵�·��
ʹ��������Ū�������һ������������Ժ��лص���
        �����ȥ�ˣ����������˼��ɾ���...........!!!!��
LONG
        );
        set("outdoors", "oldpine");
        set("objects", ([
  __DIR__"npc/hudie" : 2,
]));
        
        set("coor/x",-90);
	set("coor/y",50);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",50);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",50);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",50);
	set("coor/z",0);
	setup();
}

void reset()
{
        ::reset();
        set("exits", ([ /* sizeof() == 4 */
          "south" : __DIR__"diecong" + (random(6)+1),
          "north" : __DIR__"diecong" + (random(6)+1),
          "west" : __DIR__"diecong" + (random(6)+1),
                  "east":"/d/mj/shanjiao",
          "northeast" : __DIR__"diecong" + (random(6)+1),
        ]));
}

int valid_leave(object me, string dir)
{
        write("��ʵ��Ū���������....");
        switch(dir) {
                case "north":   write("����....�����������أ�....");    break;
break;
                case "east":    write("����....����....");      break;
                case "south":   write("�ϱ�....�������ϱߣ�....");      break;
break;
                case "west":    write("����....��....");        break;
                default:
                        write("������������....");
        }
        write("�����������ɡ�\n");
        return 1;
}

