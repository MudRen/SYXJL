// Room: /d/wuguan/xiuxishi1.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
����������ڵ���Ϣ�ң������е��ɣ����Ǵ�ɨ�ķǳ��ɾ���һ��
���̿�ǽ���ţ������ĵ��߹�ȥ���Ҹ�����˯��������
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("sleep_room", 1);
        set("exits", ([
                "west" : __DIR__"xiuxishi",
        ]));
        setup();
        replace_program(ROOM);
}
