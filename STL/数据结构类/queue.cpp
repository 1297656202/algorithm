queue<string>words;
queue<string>copy_words{words}; // A duplicate of words
front():����queue �е�һ��Ԫ�ص����á����queue�ǳ������ͷ���һ��������;���queueΪ�գ�����ֵ��δ�����
back():����queue�����һ��Ԫ�ص����á����queue�ǳ������ͷ���һ��������;���queueΪ�գ�����ֵ��δ�����
push(const T& obi):��queue��β�����һ��Ԫ�صĸ���������ͨ�����õײ������ĳ�Ա����push_ back()����ɵ�
push(T&& obj):���ƶ��ķ�ʽ��queue ��β�����Ԫ�ء�����ͨ�����õײ������ľ�����ֵ���ò����ĳ�Ա����push_ back()����ɵ�
pop():ɾ��queue �еĵ�һ��Ԫ��
size():����queue ��Ԫ�صĸ�����
empty():���queue��û��Ԫ�صĻ�������true��
emplace():�ô���emplace()�Ĳ������â�Ĺ��캯������queue��β�����ɶ���
swap(queue<T> &other q):����ǰqueue �е�Ԫ�غͲ���queue �е�Ԫ�ؽ�����������Ҫ������ͬ���͵�Ԫ�ء�Ҳ���Ե���ȫ�ֺ���ģ��swap)�����ͬ���Ĳ�����T> &other_q)������ǰ queue �е�Ԫ�غͲ��� queue �е�Ԫ�ؽ�����������Ҫ������ͬ���͵�Ԫ�ء�Ҳ���Ե���ȫ�ֺ���ģ�� swap() �����ͬ���Ĳ�����
