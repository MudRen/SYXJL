// Room: /d/wuguan/xiuxishi.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
����������ڵ���Ϣ�ң������е��ɣ����Ǵ�ɨ�ķǳ��ɾ���һ��
���̿�ǽ���ţ������ȥҲ��һ����Ϣ�ң����ϵ����˽�����Ϣ���Ѻ�
��ȥ�������ĵ��Ҹ�����˯��������
LONG );
        set("no_fight",1);
        set("sleep_room", 1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"changlang3",
                "east"  : __DIR__"xiuxishi1",                
        ]));
        setup();
        replace_program(ROOM);
}
