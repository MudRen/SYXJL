inherit ROOM;

void create()
{
        set("short", "��¨");
        set("long", @LONG
������¨���У��ۼ����̱��������Ʈ������ͷ���ľ������ȥ������
����������¥����ҫ�۵Ĺ�â��
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ ]));

        setup();
        replace_program(ROOM);
}
