// Room: /chang'an/silao.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ܶ������ҵ��Ѿ�ʪ�����ĵ��ݣ�ɢ����Ǻ�ǵ�ùζ��������¶��
һЩ��ɭɭ�Ĳ�֪��ʲô����Ĺ�ͷ����Ͱ�Ѿ�ɢ�˼ܣ�������һЩ����
�Ĵ�Ƭ����������Ѿ�������ʲô�˵���״�ˣ�����ʳ�﹩��Ҳ����û�У�
����ǽ��������𶼱����ǻ��Ե��ˡ���ֻ�����뿪�����ط���
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"jianyuguodao",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}