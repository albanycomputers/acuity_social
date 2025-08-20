<?php

/**
 * Defines the Chat entity class.
 */
class AcuitySocialChat extends EntityDefaultUIController {
  public $id;
  public $idchannel;
  public $parent;
  public $uid;
  public $created;
  public $updated;
  public $chat_message;
  public $chat_image;
  public $visibility;
  public $status;

  /**
   * Returns the entity type machine name.
   */
  public function entityType() {
    return 'acuity_social_chat';
  }

  /**
   * Returns the entity ID.
   */
  public function id() {
    return $this->id;
  }

  /**
   * Returns the channel ID this chat belongs to.
   */
  public function channelId() {
    return $this->idchannel;
  }

  /**
   * Returns the parent message ID (for threading).
   */
  public function parentId() {
    return $this->parent;
  }

  /**
   * Returns the user ID of the poster.
   */
  public function uid() {
    return $this->uid;
  }

  /**
   * Returns the message content.
   */
  public function message() {
    return $this->chat_message;
  }

  /**
   * Returns the visibility setting.
   */
  public function visibility() {
    return $this->visibility;
  }

  /**
   * Returns the moderation status.
   */
  public function status() {
    return $this->status;
  }

  /**
   * Returns the label of the entity.
   */
  public function label() {
    return $this->message();
  }

  /**
   * Returns the URI to view the chat.
   */
  public function uri() {
    return ['path' => 'social-chat/' . $this->id()];
  }

  /**
   * Saves the entity.
   */
  public function save() {
    return entity_get_controller($this->entityType())->save($this);
  }

  /**
   * Deletes the entity.
   */
  public function delete() {
    return entity_get_controller($this->entityType())->delete([$this->id()]);
  }
}