// Room: /d/wuguan/baishi.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "��ʦѧ��");
        set("long", @LONG
���ͣգ��У����������ɣ�������а��Ҳ��������а�ġ�������
���ϳ�Ϊ���֣���Ҫѡһ���ɣ�Ͷ�����£�ѧ���书�����ܳ�Ϊһ��
���֡����ǣ�����㲻����κ�һ������Ҳ�ɣ����������������书
��ѧ�������Ѱ�ң���Ҫ��ʦ��ͨ��ȴ�Ǻ����ѵġ�
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "east" : __DIR__"baishi1",
        ]));
        set("objects", ([
                __DIR__"npc/lxq" : 1,
        ]));
                
        setup();
        replace_program(ROOM);
}
