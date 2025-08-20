<?php

/**
 * Defines the ContactHeader entity class.
 */
class SocialChannel extends Entity {
  public $id;
  public $uid;
  public $parent_id;
  public $bundle;
  public $created;
  public $updated;
  public $channel_name;
  public $channel_desc;
  public $visibility;

  /**
   * Returns the entity type machine name.
   */
  public function entityType() {
    return 'social_channel';
  }

  /**
   * Returns the ID of the entity.
   */
  public function id() {
    return $this->id;
  }

  /**
   * Returns the UID (owner) of the entity.
   */
  public function uid() {
    return $this->uid;
  }

  /**
   * Returns the bundle (business, residential, etc.).
   */
  public function bundle() {
    return $this->bundle;
  }

  /**
   * Returns the chat chanel name.
   */
  public function channel_name() {
    return $this->channel_name;
  }


  /**
   * Returns the label of the entity.
   */
  public function label() {
    // Later you can link a business name here if you add one.
    // @todo Implement business name handling.
    // For now, just return a generic label.
    return $this->channel_name();
  }

    /**
   * Returns the label of the entity.
   */
  public function channel_desc() {
    // Later you can link a business description here if you add one.
    // @todo Implement business description handling.
    // For now, just return a generic description.
    return $this->channel_desc;
  }

  /**
   * Returns the label of the entity.
   */
  public function visibility() {
    // Later you can link a business visibility here if you add one.
    // @todo Implement business visibility handling.
    // For now, just return a generic visibility.
    return $this->visibility;
  }
  /**
   * Returns the URI (path) to view the entity.
   */
  public function uri() {
    return ['path' => 'social-channel/' . $this->id()];
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
