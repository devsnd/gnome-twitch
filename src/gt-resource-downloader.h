#ifndef GT_RESOURCE_DOWNLOADER_H
#define GT_RESOURCE_DOWNLOADER_H

#include <glib-object.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

G_BEGIN_DECLS

#define GT_TYPE_RESOURCE_DOWNLOADER gt_resource_downloader_get_type()

G_DECLARE_FINAL_TYPE(GtResourceDownloader, gt_resource_downloader, GT, RESOURCE_DOWNLOADER, GObject);

struct _GtResourceDownloader
{
    GObject parent_instance;
};

GtResourceDownloader* gt_resource_downloader_new(const gchar* filepath);
GdkPixbuf*            gt_resource_downloader_download_image(GtResourceDownloader* self, const gchar* uri, const gchar* name, gboolean cache, GError** error);
void                  gt_resource_downloader_download_image_async(GtResourceDownloader* self, const gchar* uri, const gchar* name, gboolean cache, GAsyncReadyCallback cb, GCancellable* cancel, gpointer udata);
GdkPixbuf*            gt_resource_donwloader_download_image_finish(GtResourceDownloader* self, GAsyncResult* result, GError** error);

G_END_DECLS

#endif