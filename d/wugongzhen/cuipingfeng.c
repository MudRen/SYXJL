// cuipingfeng.c �����嶥
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "�����嶥");
        set("long", @LONG
�����Ǵ�����ķ嶥��������������ɽ�ĵ�һ�壬Ҳ�����һ��ɽ
�塣���±߽���һ��Сͤ�ӣ����߽�ͤ��ƾ��Զ����Զ����ɽ�����Ư��
���ƣ�����������ʲô������ɽ����������ϧ�����ƾ���ס�ˡ������ο�
Ҳ��ͤ��Ъ�ţ������������Ŵ˵�������
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southdown" : __DIR__"baishulin3",
        ]));
         set("objects",([
                  "/d/quanzhen/npc/chongyang" : 1,
          ]));

        set("coor/x",-100);
	set("coor/y",190);
	set("coor/z",50);
	set("coor/x",-100);
	set("coor/y",190);
	set("coor/z",50);
	set("coor/x",-100);
	set("coor/y",190);
	set("coor/z",50);
	set("coor/x",-100);
	set("coor/y",190);
	set("coor/z",50);
	setup();
        replace_program(ROOM);
}

