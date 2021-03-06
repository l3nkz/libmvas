#include <mvas/segment.h>
#include <mvas/vas.h>

#include <linux/vas.h>

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>


segid_t segment_create(const char * const name, unsigned long start,
                       unsigned long end, mode_t mode)
{
    segid_t id;

    if (!name || (end <= start)) {
        errno = EINVAL;
        return -1;
    }

    id = syscall(SYS_vas_seg_create, name, start, end, mode);
    if (id < 0) {
        errno = -id;
        return -1;
    } else {
        return id;
    }
}

segid_t segment_create_sz(const char * const name, unsigned long start,
                          unsigned long size, mode_t mode)
{
    return segment_create(name, start, start + size, mode);
}

int segment_delete(segid_t sid)
{
    long ret;

    if (sid <= 0) {
        errno = EINVAL;
        return -1;
    }

    ret = syscall(SYS_vas_seg_delete, sid);
    if (ret < 0) {
        errno = -ret;
        return -1;
    } else {
        return 0;
    }
}

segid_t segment_find(const char * const name)
{
    segid_t id;

    if (!name) {
        errno = EINVAL;
        return -1;
    }

    id = syscall(SYS_vas_seg_find, name);
    if (id < 0) {
        errno = -id;
        return -1;
    } else {
        return id;
    }
}

int segment_attach(vasid_t vid, segid_t sid, int type)
{
    long ret;

    if (vid <= 0 || sid <= 0) {
        errno = EINVAL;
        return -1;
    }

    ret = syscall(SYS_vas_seg_attach, vid, sid, type);
    if (ret < 0) {
        errno = -ret;
        return -1;
    } else {
        return 0;
    }
}

int segment_detach(vasid_t vid, segid_t sid)
{
    long ret;

    if (vid <= 0 || sid <= 0) {
        errno = EINVAL;
        return -1;
    }

    ret = syscall(SYS_vas_seg_detach, vid, sid);
    if (ret < 0) {
        errno = -ret;
        return -1;
    } else {
        return 0;
    }
}

int segment_getattr(segid_t sid, struct vas_seg_attr * const attr)
{
    long ret;

    if (sid <= 0 || !attr) {
        errno = EINVAL;
        return -1;
    }

    ret = syscall(SYS_vas_seg_getattr, sid, attr);
    if (ret < 0) {
        errno = -ret;
        return -1;
    } else {
        return 0;
    }
}

int segment_setattr(segid_t sid, const struct vas_seg_attr * const attr)
{
    long ret;

    if (sid <= 0 || !attr) {
        errno = EINVAL;
        return -1;
    }

    ret = syscall(SYS_vas_seg_setattr, sid, attr);
    if (ret < 0) {
        errno = -ret;
        return -1;
    } else {
        return 0;
    }
}
