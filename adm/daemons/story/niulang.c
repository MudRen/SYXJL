// story:niulang 牛郎织女

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "七月初七，鹊桥相会。",
        "喜鹊飞呀飞～～～",
        "织女：牛郎哥哥，你可想死我了。",
        "牛郎：织女妹妹，我也很想你啊，这一年来我无时无刻不在思念你啊。",
        "织女：唉，春去秋来总依旧，分分离离何时了。",
        "牛郎哽咽道：我的好老婆啊...",
        "王母娘娘：这两个家伙，酸死我了，那个... 那个贱人！",
        "智多星：王母息怒，少忍，少忍。",
        "牛郎和织女犹在卿卿我我。",
        "蓦然织女大怒，手里掐着一根头发，喝道：牛郎，你快给我说清楚，这是哪儿来的？",
        "牛郎结结巴巴道：老婆... 这，这是不是你的啊？",
        "织女冷笑道：哼！我的头发可不是这个样子的，这头发分明是一个凡人的！",
        "牛郎头里嗡嗡直叫。",
        "织女猛摇牛郎，喊道：你快给我说清楚！说清楚呀！",
        "牛郎喃喃道：我，我这是跳到银河里也洗不清了。",
        "织女淡然道：好，你就跳到银河里吧，如果你跳了，我就认为你是清白的。",
        "牛郎苦着脸道：老婆，你这不是要害死我嘛，这，我这跳进去，不立刻变成冰棍了。",
        "织女大怒，给牛郎就是一耳光，“啪”的一声异常响亮，喝道：滚，我不是你老婆！",
        "织女飘然而去，渺然不见踪影",
        "牛郎捂着脸，半晌才清醒过来，嘀咕道：他奶奶的，这婊子，没点三从四德，休了她！",
        "牛郎低头踉踉跄跄而去。",
        "智多星：怎么样，王母娘娘，小人这条计还算不错吧。",
        "王母娘娘颌然赞许道：你小子不赖，难怪能做上梁山第三把交椅，有点门道。",
        "喜鹊飞呀飞～～～",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}
