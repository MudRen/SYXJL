
// Room: /chang'an/beilin.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�������ڱ�ʯ�������ֶ��������ڲ���������ʯ�̾��顶����ʯ������
��ʯ̨Т�����������ؾ��������й�������ŷ��ѯ�ġ��ʸ�������������
��ġ����������͡����ϼ�����������Ȩ�ġ����������������صġ�ǧ
���ı���������ġ���ǧ���ı������������ġ����ؼǱ������Լ����δ�
���ظ�������������ʯ��
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"nandajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}