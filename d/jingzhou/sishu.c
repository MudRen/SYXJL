
// Room: /jingzhou/sishu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "˽��");
        set("long", @LONG
������˽�ӵĽ��ã�����������һ����Ⱦ��һλׯ���������������
������ɽ���������̫ʦ���Ͻ�ѧ���Ǿ��Ǳ��ش����������ˡ�һ�Ź���
��Ȼ���鰸������������ǰ�棬���ϰ��ż��������˵���װ�鼮�������
ѧ����������������ҡͷ���Եر��Ű˹��ġ��Ϸ��Ӹշ���ʥּȡ���˰�
��ѧλ���ʸ񣬾����ſ�������Ժ������ѧλ�����(board)��
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"xidajie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}